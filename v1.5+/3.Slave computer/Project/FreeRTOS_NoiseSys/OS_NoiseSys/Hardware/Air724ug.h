#ifndef __AIR724UG_H
#define __AIR724UG_H

#define REV_OK		0	// received buffer finished
#define REV_WAIT	1	// received buffer unfinished

void Air724_Init(void);
void Air724_PDPact(void);
void Air724_Reset(void);
_Bool Air724_SendCmd(char *cmd, char *res);

#endif
