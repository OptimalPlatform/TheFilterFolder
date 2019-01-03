//stemwin window for the choice of filter

#include "main.h"
#include "DIALOG.h"
#include "GUI.h"
#include <stdlib.h>

char fType;
uint8_t doneFlag;
/*********************************************************************
 *
 *       Static data
 *
 **********************************************************************
 */

/* Dialog resource of numpad */
static const GUI_WIDGET_CREATE_INFO _aDialogFilterChoice[] =
{
		/*  Function                 Text      Id                 Px   Py   Dx   Dy */
		{ WINDOW_CreateIndirect, 0, 0, 0, 0, 240, 320 },
		{ BUTTON_CreateIndirect, "Kalman Filter", GUI_ID_USER + 0, 5, 5, 225, 90 },
		{ BUTTON_CreateIndirect, "Wiener Filter", GUI_ID_USER + 1, 5, 100, 225, 90 },
		{ BUTTON_CreateIndirect, "No Filter", GUI_ID_USER + 2, 5, 195, 225 , 90 }
};

/*********************************************************************
 *
 *       Static code
 *
 **********************************************************************
 */
/*********************************************************************
 *
 *       _cbDialogNumPad
 *
 * Purpose:
 *   Callback function of the numpad.
 */

static void _cbDialogFilterChoice(WM_MESSAGE * pMsg) {
	int i, NCode, Id, Pressed = 0;
	WM_HWIN hDlg, hItem;
	hDlg = pMsg->hWin;
	switch (pMsg->MsgId) {

	case WM_PAINT:
		GUI_SetBkColor(0x000000);
		GUI_Clear();
		break;

	case WM_INIT_DIALOG:
		for (i = 0; i <= GUI_COUNTOF(_aDialogFilterChoice); i++) {
			hItem = WM_GetDialogItem(hDlg, GUI_ID_USER + i);
			BUTTON_SetFocussable(hItem, 1); // Set all buttons non focussable
		}
		break;

	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc); // Id of widget
		NCode = pMsg->Data.v; // Notification code
		int Key = 0;
		switch (NCode) {
		case WM_NOTIFICATION_RELEASED:
			if (Id == GUI_ID_USER + 0)
				//The kalman button is pressed
			{
				fType = 'K';
				doneFlag = 1;
				Key = 0;
				GUI_EndDialog(hDlg, 1);
			} else if (Id == GUI_ID_USER + 1)
				//the wienerbutton is pressed
			{
				fType = 'W';
				doneFlag = 1;
				Key = 0;
				GUI_EndDialog(hDlg, 1);
			} else if (Id == GUI_ID_USER + 2 )
				//no filter is pressed
			{
				fType = 'N';
				doneFlag = 1;
				Key = 0;
				GUI_EndDialog(hDlg, 1);
			}
			GUI_SendKeyMsg(Key, Pressed); // Send a key message to the focussed window
			break;
		case WM_NOTIFICATION_CLICKED:
			Pressed = 1;
			break;
		}
		break;
		default:
		WM_DefaultProc(pMsg);
	}
}

/**********************b***********************************************

 *
 *       MainTask
 */

void FilterChoice(struct FilterState* fState) {
	WM_HWIN hMenu;
	fType = fState->filterType;
	doneFlag = fState->doneFlag;

	GUI_SelectLayer(0);

	hMenu = GUI_CreateDialogBox(_aDialogFilterChoice, GUI_COUNTOF(_aDialogFilterChoice),_cbDialogFilterChoice, WM_HBKWIN, 0, 0);

	WM_SetCallback(hMenu, _cbDialogFilterChoice);
	WIDGET_SetFocusable(hMenu, 1);

	//loops till menus closes down
	while(doneFlag == 0){
		GUI_Delay(200);
	}
	fState->filterType = fType;
}

/*************************** End of file ****************************/

