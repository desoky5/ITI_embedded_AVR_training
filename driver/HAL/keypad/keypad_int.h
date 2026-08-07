

#ifndef HAL_KPD_KPD_INT_H_
#define HAL_KPD_KPD_INT_H_

#define KPD_ROWS       4
#define KPD_COLS       4

#define NO_KEY         0xFF

void HKPD_vInit(void);


u8 HKPD_u8GetPressedKey(const u8 KeyMap[KPD_ROWS][KPD_COLS]);



#endif /* HAL_KPD_KPD_INT_H_ */
