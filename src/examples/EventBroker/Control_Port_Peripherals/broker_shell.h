#ifndef __BROKER_SHELL_H
#define __BROKER_SHELL_H

/******************************************************************************
**
**  $Id: broker_shell.h,v 1.3 1994/11/23 18:28:26 vertex Exp $
**
******************************************************************************/

#include "types.h"
#include "event.h"

/* commenting out */
/* an include file */
/* cuts all code associated */
/* with that device from */
/* the broker shell utility code */
/* and effectively removes support */
/* for that device. */
/* i.e. the lgun .h file */
/* is commented out (that code is not done) */
/* so #ifdef directives clip out all related code */

#include "bs_joystick.h"
#include "bs_cpad.h"
#include "bs_mouse.h"
/* #include "bs_lgun.h" */

#define BS_XRES 320
#define BS_YRES 240
#define BS_ZRES 100

#define BS_SCRNXS 640
#define BS_SCRNYS 480

enum {
	BS_STICK=0x01,
	BS_MOUSE=0x02,
	BS_CPAD=0x04,
	BS_LGUN=0x08,
	BS_PORT_CHANGE=0x10,
	BS_OTHER_SIGNAL=0x20
};

extern int BS_ConnectEventBroker(void);

#ifdef __BS_JOYSTICK_H
extern uint32 BS_WatchingJoyStick(void);
extern int BS_WatchJoyStick(int);
#define BS_IgnoreJoyStick() BS_WatchJoyStick(-1)
#else
typedef void BS_StickDatls a;
#endif /*  __BS_JOYSTICK_H */

#ifdef __BS_CPAD_H
extern uint32 BS_WatchingCPad(void);
extern int BS_WatchCPad(int);
#define BS_IgnoreCPad() BS_WatchCPad(-1)
#else
typedef void BS_CPadData;
#endif /*  __BS_CPAD_H */

#ifdef __BS_LGUN_H__
extern uint32 BS_WatchingLGun(void);
extern int BS_WatchLGun(int);
#define BS_IgnoreLGun() BS_WatchLGun(-1)
#else
typedef void BS_LGunData;
#endif /*  __BS_LGUN_H */

#ifdef __BS_MOUSE_H
extern uint32 BS_WatchingMouse(void);
extern int BS_WatchMouse(int);
#define BS_IgnoreMouse() BS_WatchMouse(-1)
#else
typedef void BS_MouseData;
#endif /* __BS_MOUSE_H */

extern int32 BS_GetPeripheralCount(uint32 devMask);
extern int BS_CountPeripherals(void);

extern int BS_DisconnectBroker(void);

extern uint32 BS_GetOtherSignals(void);

extern int32 BS_NiceWaitEvent(
						BS_StickData **sdp,
						BS_CPadData **cpdp,
						BS_MouseData **mdp,
						BS_LGunData **lgdp);

#endif /* __broker_shell_h__ */
