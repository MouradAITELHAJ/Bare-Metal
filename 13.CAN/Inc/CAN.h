#ifndef CAN_H_
#define CAN_H_

#include "stm32g4xx.h"
#include <stdint.h>

#define CAN (1U << 25)
#define FLSSA_OFFSET (uint32_t)(0x0000U)
#define FLESA_OFFSET (uint32_t)(0x0070U)
#define RXFIFO0_OFFSET (uint32_t)(0x00B0U)
#define RXFIFO1_OFFSET (uint32_t)(0x0188U)
#define EFSA_OFFSET (uint32_t)(0x0260U)
#define TBSA_OFFSET (uint32_t)(0x0278U)

#define FLSSA (SRAMCAN_BASE + FLSSA_OFFSET)
#define FLESA (SRAMCAN_BASE + FLESA_OFFSET)
#define RXFIFO0 (SRAMCAN_BASE + RXFIFO0_OFFSET)
#define RXFIFO1 (SRAMCAN_BASE + RXFIFO1_OFFSET)
#define EFSA (SRAMCAN_BASE + EFSA_OFFSET)
#define TBSA (SRAMCAN_BASE + TBSA_OFFSET)

#define FilterElements 28
#define ExtendedFilterElement 8
#define RxFIFO0Element 3
#define RxFIFO1 3
#define TxEventFifo 3
#define TxFifo 3

typedef struct {
    int ID : 29;
    int RTR : 1;
    int XTD : 1;
    int ESI : 1;
} TxBufferT0;

typedef struct {
    uint32_t StandardFilterSA;
    uint32_t ExtendedFilterSA;
    uint32_t RxFIFO0SA;
    uint32_t RxFIFO1SA;
    uint32_t TxEventFIFOSA;
    uint32_t TxFIFOQSA;
} FDCAN_MsgRamAddressTypeDef;

void CAN_CONFIG(void);
void CAN_WRITE(char *msg, int DLC, int ID, int RTR);

#endif /* CAN_H_ */