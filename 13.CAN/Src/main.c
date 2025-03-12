#include "can.h"

int main(void) {
    // Main function (empty in your original code)
}

void CAN_CONFIG(void) {
    RCC->APB1ENR1 |= CAN;
    FDCAN1->ILE |= 0x3;
    FDCAN1->IE |= 0x812;
    FDCAN1->CCCR |= 0x3;
    FDCAN1->CCCR &= ~(1U << 8);
    FDCAN1->CCCR &= ~(1U << 1);
    FDCAN1->CCCR &= ~(1U << 0);
}

void CAN_WRITE(char *msg, int DLC, int ID, int RTR) {
    FDCAN_MsgRamAddressTypeDef *MessageRAM;
    MessageRAM->TxFIFOQSA = TBSA;

    TxBufferT0 T0 = {
        .ID = ID,
        .XTD = 0x0,
        .ESI = 0x0,
        .RTR = RTR
    };

    uint32_t *TxMsg;
    TxMsg = (uint32_t *)MessageRAM->TxFIFOQSA;

    *TxMsg = ID | (RTR << 29) | (T0.XTD << 30) | (T0.ESI << 31);

    TxMsg++;

    *TxMsg |= (DLC << 16);
    TxMsg++;

    for (uint32_t ByteCounter = 0; ByteCounter < DLC; ByteCounter += 4U) {
        *TxMsg = (((uint32_t)msg[ByteCounter + 3U] << 24U) |
                  ((uint32_t)msg[ByteCounter + 2U] << 16U) |
                  ((uint32_t)msg[ByteCounter + 1U] << 8U) |
                  (uint32_t)msg[ByteCounter]);
        TxMsg++;
    }
}

void ReceiveMessage(uint32_t RxLocation, uint32_t pRxHeader, uint8_t pRxData) {
    uint32_t RxAddress;
    uint8_t pData;
    uint32_t ByteCounter;
    uint32_t GetIndex = 0;

    if (RxLocation == 0) {
        if ((FDCAN1->RXF0S & FDCAN_RXF0S_F0F) && (FDCAN1->RXGFC & FDCAN_RXGFC_F0OM))
            GetIndex = 1U;
        GetIndex += (FDCAN1->RXF0S & FDCAN_RXF0S_F0GI) >> FDCAN_RXF0S_F0GI_Pos;
        RxAddress = (uint32_t)(FDCAN1->msgRam.RxFIFO0SA + (GetIndex * SRAMCAN_RF0_SIZE));
    } else {
        if ((FDCAN1->RXF1S & FDCAN_RXF1S_F1F) && (FDCAN1->RXGFC & FDCAN_RXGFC_F1OM))
            GetIndex = 1U;
        GetIndex += (FDCAN1->RXF1S & FDCAN_RXF1S_F1GI) >> FDCAN_RXF1S_F1GI_Pos;
        RxAddress = (uint32_t)(FDCAN1->RxFIFO1SA + (GetIndex * SRAMCAN_RF1_SIZE));
    }

    pRxHeader[0] = RxAddress;
    RxAddress++;
    pRxHeader[1] = RxAddress;
    RxAddress++;

    pData = (uint8_t *)RxAddress;
    for (ByteCounter = 0; ByteCounter < DLCtoBytes[(pRxHeader[1] >> 16U) & 0xF]; ByteCounter++) {
        pRxData[ByteCounter] = pData[ByteCounter];
    }

    if (RxLocation == 0) FDCAN1->RXF0A = GetIndex;
    else FDCAN1->RXF1A = GetIndex;
}