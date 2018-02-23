/**
***     WPAO_DEF.h              ATK-PANELS
***                             AnalogOut Module Prototypes
***                             and Manifest constants.
***
***     Andrew Thomson
***
***     This module hold all module prototypes. Inaddition most
***     manifest constants and structure declarations are held here.
***
***     Associated Files :      
***
***     Version History :
***
**/



/**
***     WPAO_MSS.c Module Prototypes
**/
int PASCAL WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance,
					   LPSTR lpszCmdLine, int nCmdShow );


LRESULT CALLBACK AnalogOut_WndProc ( HWND hwnd, WORD wMsg,
					   WPARAM wParam, LPARAM lParam );


VOID AnalogOut_OnKeyDown ( HWND hwnd, long vk, BOOL fDown,
						long cRepeat, long flags );


VOID AnalogOut_OnKeyUp ( HWND hwnd, long vk, BOOL fDown,
						long cRepeat, long flags );


BOOL AnalogOut_OnCreate ( HWND hwnd, CREATESTRUCT * lpCreateStruct );


VOID AnalogOut_OnSize ( HWND hwnd, long state, long cx, long cy );


VOID AnalogOut_OnPaint ( HWND hwnd );


VOID AnalogOut_OnCommand ( HWND hwnd, long id, HWND hwndCtl, long codeNotify );


VOID AnalogOut_OnClose ( HWND hwnd );


VOID AnalogOut_OnDestroy ( HWND hwnd );


VOID AnalogOut_OnVScroll ( HWND hwnd, HWND hwndCtl, long code, long pos );


DWORD AnalogOut_OnMenuChar ( HWND hwnd, long ch, long flags, HMENU hMenu );


VOID AnalogOut_OnSetFocus ( HWND hwnd, HWND hwndOldFocus );

HBRUSH AnalogOut_OnCtlColor ( HWND hwnd, HDC hdc, HWND hwndChild, long type);

VOID AnalogOut_OnReadChan ( HWND hwnd, long lChannelIndex );

VOID AnalogOut_OnWriteChan ( HWND hwnd, long lChannelIndex );

VOID AnalogOut_OnGetMinMaxInfo ( HWND hwnd, MINMAXINFO *lpMinMaxInfo );

VOID AnalogOut_OnLButtonDown ( HWND hwnd, BOOL fDoubleClick,
					 long x, long y, long keyFlags );


void SetChannelFocus  ( HWND hwndParent, short nFocusChannel );

void KillChannelFocus ( HWND hwndParent, short nFocusChannel );

void ResizeClientRects ( HWND hwnd, long cx, long cy  );



/**
***     Callback and dialog (EXPORT) function prototypes WPAO_EXP.c
**/

BOOL WINAPI About_DlgProc ( HWND hdlg, WORD msg, WORD wParam,
							    LONG lParam );

LRESULT CALLBACK EditBox_WndProc ( HWND hWnd, WORD iMessage,
					   WPARAM wParam, LPARAM lParam );


/**     Drawing Routines; Module WPAO_DRW.c
***
**/
short CreateStatusBar ( HWND hWndMain  );
short DrawStatusBar   ( HDC  hClientDC );
short UpdateStatusBar ( HWND hWndMain  );

short CreateButtonBar ( HWND hWndMain  );
short DrawButtonBar   ( HDC  hClientDC );
short UpdateButtonBar ( HWND hWndMain  );

short CreateDataArea  ( HWND hWndMain  );
short DrawDataArea    ( HDC  hdcClient, LPPAINTSTRUCT lpps );
short UpdateDataArea  ( HWND hWndMain  );
short UpdateChannelEdittext ( HWND hwnd, long lChannel );



short CreateScrollBar ( HWND hWndMain  );
short UpdateScrollBar ( HWND hWndMain  );

short UpdateMenuBar ( HWND hWndMain );
VOID  SizeControls ( VOID );

short DepressRect ( HDC hDC, LPRECT lprectShadedArea );

void DrawBitmap ( HDC hDC, long lXStart, long lYStart,
					HBITMAP hbmMask, HBITMAP hbmBitmap );


/**     PTK_DDE Module prototypes
**/
short PTKInitializeDDEService ( HWND hwndApplication, char *szServiceName );
short PTKTerminateDDEService  ( void );
VOID  PTKAdviseDDE ( short nItem );
short LoadDDECallBackProc ( VOID );
short FreeDDECallBackProc ( VOID );


/**
***     WPAO_CYC Module Prototypes
**/
short   StartAutoCycle      ( VOID );
short   ServiceAutoCycle    ( VOID );
short   StopAutoCycle       ( VOID );

DWORD   GetMillisecondCount ( VOID );




/**
***     WPAO_UTL        Module Prototypes
***
***     including client area mapping conversion functions.
**/
short ChannelNumberToTextLine ( short nChannelNumber );

short TextLineToChannelNumber ( short nTextLine );

short PixelPositionToChannelNumber ( WORD wYPos );

LONG  ChannelToMouseCoords ( short nChannel );

VOID  InvalidateChannel ( HWND hwnd, long lChannel, long lChanFlags );

void  GetFontMetrics ( HWND hwndClient, HFONT hFont,
				long *plHeight, long *plWidth );


short AllowSetupConfiguration ( HWND hwnd, PIMSSETUP pimssSetup );

short PreventSetupConfiguration ( HWND hwnd, PIMSSETUP pimssSetup );

BOOL  InvokeWinHelp ( HWND hWnd, WORD wCommand, DWORD dwData );

short AddConnectionToArray ( char *szConnection, PCHANNELINFO lpSummary,
						     short nNumSummaryChans );

void  ExtractCmdLineArg ( HWND hwndMain, LPSTR lpszCmdLine );

VOID  UpdateTitleBar ( HWND hwndMain );

void SetChannelFocus ( HWND hwndParent, short nFocusChannel );




/**
***     WPAO_SET        Module Prototypes for Setup File Functions
***
**/
short SaveAppSetup ( char *szAppSetup );

short LoadAppSetup ( char *szAppSetup );





/**     Message Crackers for user defined messages
***
***     WM_READCHAN :
***             void Cls_OnReadChan (HWND hwnd, WORD unChannelIndex );
***     WM_WRITECHAN
***             void Cls_OnWriteChan (HWND hwnd, WORD unChannelIndex );
**/
#define HANDLE_WM_READCHAN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd),(wParam)))
#define FORWARD_WM_READCHAN(hwnd, unChannelIndex, fn) \
    (void)(fn)((hwnd), WM_READCHAN, unChannelIndex, 0L)


#define HANDLE_WM_WRITECHAN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd),(wParam)))
#define FORWARD_WM_WRITECHAN(hwnd, unChannelIndex, fn) \
    (void)(fn)((hwnd), WM_WRITECHAN, unChannelIndex, 0L)



/**
***     PANELINFO structure.
***
***     This structure is used to store general information
***     pertaining to the panel application. A structure of
***     this type should be declared statically in the
***     application.
***
**/
typedef struct PANELINFOtag {

	/**     Setup file specification
	**/
	char    szFileSpec [ _MAX_PATH ];

	long   lHeight;                  /* Height of Client Area      */
	long   lWidth;                   /* Width of Client Area       */


	short   nFirstChanVisible;        /* Chan in First Visible col  */
	short   nNumRowsVisible;          /* Visible data Rows          */
	short   nMaxRowsVisible;          /* Visible Rows IF MAXIMIZED  */
	short   nFocusChannel;            /* Channel with highlight     */


	long    lRowHeight;               /* Phy height of one data row */


	long    lTextHeight;              /* Std Text Height (helv_8)   */
	long    lAveTextWidth;            /* Std Text Width  (helv_8)   */

	long    lLargeTextHeight;         /* 'Status Bar' Text Height   */
	long    lLargeTextWidth;          /* 'Status Bar' text Width    */

	short   nStatus;                  /* see STATUS_ constants      */
	short   nNumDDELinks;             /* How many DDE conversations */

	short   nMode;                    /* MODE_DEFFERED\MODE_IMMEDIATE */

	DWORD   dwMillisecsLastCycle;     /* Time last cycle occured    */
	DWORD   dwMillisecsInterval;      /* Interval in millisecs      */

	/**     DDE server support
	**/
	BOOL    bDDEEnabled;
	char    szDDEServiceName [ ATK_MAX_DDE_SERVICE_NAME ];


} PANELINFO, *PPANELINFO;



/**     Channel information additionally required to that stored in
***     the toolkit ATKCHANINFO structures. Use 'od' prefix on structures
***     declared of this type.  A handle/ptr pair for an array of these
***     structures ( one per connection ) will be stored in the CONNECTIONS
***     structure.
**/
typedef struct OUTPUTDATA {

	BOOL    bWriteData;                     /* Send szNewValue if TRUE  */
	char    szNewValue [ MAX_VALUE + 1 ];   /* String to O/P over IML   */
	short   nWriteError;                    /* Error incurred when sent */

} OUTPUTDATA, *POUTPUTDATA, *LPOUTPUTDATA;





/**
***     CONNECTIONS structure.
***
***     This structure should be used to store application information
***     specifically related to the current IMS connections. The structure
***     includes a pointer to an array of CHANINFO structures which will
***     be created and maintained by the Application Toolkit.
***
**/
typedef struct CONNECTIONStag {

	HANDLE           hIMSLibrary;           /* Handle to IMSLib         */
	short            nIMLInterface;         /* Handle to IML Interface  */

	IMSSETUP         imsSetup;              /* IMS Setup structure      */
	BOOL             bIMSSetupLoaded;       /* using an IMS Setup       */

	short            nNumConnected;         /* Actual Number Connected  */
	short            nMaxConnections;       /* Max possible connections */
	WORD             wChanTypes;            /* Types to connect         */

	LOCALHANDLE      hConnections;          /* Hdl to ATKChanInfo array */
	PATKCHANINFO     pciConnections;        /* Ptr to ATKChanInfo array */


	LPOUTPUTDATA     lpodOutputData;        /* FPtr to OUTPUTDATA array */

} CONNECTIONS, *PCONNECTIONS;






/**     This structure contains information pertaining to each
***     push-button on the client area's button bar. The following
***     are stored :
***
***             hButtonWnd  - The Window handle to the button.
***             dwStyle     - The style used to create the button
***             szText      - Pointer to the button text
***             nXPos/nYPos - The buttons position in client units.
***
***     This array is initialized by CreateButtonBar.
***
**/
typedef struct BUTTONBARtag {

	HWND    hButtonWnd;
	DWORD   dwStyle;
	char    *szText;
	long   lXPos;
	long   lYPos;

} BUTTONBAR;




/**
***     Key Dimensions of Client Area Controls
***     Button and Status Bars...
***
***     This structure is statically decalared as 'controls' and
***     initialized using the fn
**/
typedef struct CONTROLStag {

	short   nPushButtonHeight;
	short   nPushButtonWidth;
	short   nEditBoxLength;
	short   nEditBoxHeight;
	short   nEditBoxLabelLength;
	short   nBarBorder;
	short   nSingleBarHeight;
	short   nDoubleBarHeight;
	short   nMinSingleBarWidth;
	short   nStatusBarHeight;
	short   nScrollBarHeight;

} CONTROLS;


/**     Manifests for 'PANELINFO.nStatus' field
**/
#define NUM_STATES                      4
#define STATUS_NOSETUP                  0
#define STATUS_IDLE                     1
#define STATUS_AUTO                     2
#define STATUS_BUSY                     3


/**     Manifests for 'PANELINFO.nMode' field
**/
#define MODE_IMMEDIATE                  0
#define MODE_DEFERRED                   1


/**     Help File Manifests
**/
#define HELP_FILE_NAME                  "AnOut"
#define HELP_FILE_EXT                   "hlp"


/**     Manifests used by Stuart's GetMillisecCount function
**/
#define TIMER_CTRL      0x43            /* System 8254 control register   */
#define COUNT_0         0x40            /* System 8254 Counter 0 data reg */




/**     General Manifests
**/
#define MAX_APPLICATION_CONNECTIONS     9999
#define APPL_SETUP_SECTIONNAME          "AnalogOut"
#define DDE_SERVICE_NAME                "AnalogOut"
#define MAX_KEY_LENGTH                  256

#define MIN_CYCLE_INTERVAL              100L            /* 100 millisecs    */
#define MAX_CYCLE_INTERVAL              9999000L        /* 9999 secs        */
#define MAX_INTERVAL_LEN                15              /* Length as string */


#define BITMAP_WIDTH                    16      /* Exclaimation bitmap dims */
#define BITMAP_HEIGHT                   16

/**     This define the maximum number of data text rows which are
***     supported on the screen. On a VGA approximately 20 text rows
***     are visible on maximized client...
**/
#define MAX_CHAN_BUTTONS                100
#define MAX_SUPPORTED_DATAROWS          100


/**
***     Manifests used by function InvalidateChannel to identify which
***     fields have been invalidated. These are bit flags which may be
***     OR'ed together into a short variable.
**/
#define CHANFIELD_NAME                  1
#define CHANFIELD_VALUE                 2
#define CHANFIELD_UNITS                 4
#define CHANFIELD_ALARM                 8
#define CHANFIELD_BITMAP                16


/**     Button bar\Control Manifests
**/
#define NUM_BUTTONS                     1       /* Single Mode Button   */

#define B_MODE                          0       /* Indexes into array   */
						/* of BUTTON structures */


#define MAX_MODE_TEXT                   20      /* mode description text */

/**     Status Bar Manifests
**/
#define NUM_STATUS_BAR_ITEMS            2
#define STATUS_BAR_ITEM_LENGTH          15      /* n characters per box    */




/**     Menu Item Identifiers and user defined Window messages
***
**/
#define WM_READCHAN             ( WM_USER + 0 )
#define WM_WRITECHAN            ( WM_USER + 1 )

#define IDM_EXIT                100
#define IDM_LOADIMS             101
#define IDM_SAVE_SETUP          102
#define IDM_RESTORE_SETUP       103
#define IDM_OUTPUTS             104
#define IDM_HELP_CONTENTS       105
//#define IDM_HELP_ON_HELP        106
#define IDM_ABOUT               107
#define IDM_DDE                 108
#define IDM_INIT_NEW_SETUP      109

/**     Client Area Control IDs
**/
#define IDC_EDITBOX             200
#define IDC_VSCROLL             201
#define IDC_TEXTROW_EDIT        500     /* This is the ID for first editbox */


#define IDC_BUTTON_START        202
#define IDC_MODE_BUTTON         ( IDC_BUTTON_START + 0 )




/**     Application's Internal Error Codes
***
**/
#define ERR_INVALID_INTERVAL            1000
#define ERR_NO_LOCAL_MEMORY             1001
#define ERR_NO_GLOBAL_MEMORY            1002
#define ERR_FILE_CREATION               1003
#define ERR_FILE_WRITE                  1004
#define ERR_INVALID_FILENAME            1005
#define ERR_CHAN_NOT_IN_SUMMARY         1006
#define ERR_USER_ABORTED                1007
#define ERR_INVALID_CMDLINE_ARG         1008
#define ERR_ALL_CONNECTIONS_MISSING     1009
#define ERR_ALL_CHANS_IN_ERROR          1010
#define ERR_DEMO_VIOLATED               1011
#define ERR_UNABLE_TO_SAVE_SETUP        1012
#define ERR_NOT_PROTECT_MODE            1013
#define ERR_DDE_INIT_FAIL               1014
#define ERR_INTERVAL_TOO_SMALL          1015
#define ERR_INTERVAL_TOO_LARGE          1016
#define ERR_DDE_ITEM_NOT_SUPPORTED      1017
#define ERR_DUPLICATE_SERVICE_NAME      1018
