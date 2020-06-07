#ifndef CONFIG_H
#define CONFIG_H

/* Button definitions */
#define MOD1            Mod1Mask    /* ALT key */
#define MOD4            Mod4Mask    /* Super/Windows key */
#define CONTROL         ControlMask /* Control key */
#define SHIFT           ShiftMask   /* Shift key */

/* General settings */
#define MASTER_SIZE     0.5       /* master-stack ratio */
#define SHOW_PANEL      True      /* show panel by default on exec */
#define TOP_PANEL       True      /* False means panel is on bottom */
#define PANEL_HEIGHT    25        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    TILE     /* TILE EQUAL */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_MOUSE    False     /* Focus the window the mouse just entered */
#define FOLLOW_WINDOW   True     /* Follow the window when moved to a different desktop */
#define CLICK_TO_FOCUS  True      /* Focus an unfocused window when clicked */
#define WIN_LIMIT		3		  /* Maximum number of windows allowed per desktop */
#define BORDER_WIDTH    8         /* window border width */
#define FOCUS           "#371d5e" /* focused window border color   */
#define UNFOCUS         "#ffb6c1" /* unfocused window border color */
#define DESKTOPS        7        /* number of desktops - edit DESKTOPCHANGE keys to suit */
#define DEFAULT_DESKTOP 0         /* the desktop to focus on exec */
#define MINWSZ          50        /* minimum window size in pixels */
#define USELESSGAP      15         /* the size of the useless gap in pixels */
#define GLOBALGAPS      True      /* use the same gap size on all desktops */
#define INVERT          False     /* use alternative modes by default */
#define AUTOCENTER      True      /* automatically center windows floating by default */
#define OUTPUT_TITLE    False     /* output the title of the currently active window */

#define XF86MonBrightnessDown           0x1008ff03
#define XF86MonBrightnessUp              0x1008ff02

#define XF86AudioLowerVolume            0x1008ff11   
#define XF86AudioRaiseVolume            0x1008ff13 
#define XF86AudioMute            		0x1008ff12

/* Shell command helper - DO NOT EDIT */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/* Shell commands */
static const char *termcmd[] = { "urxvt",     NULL };
static const char *menucmd[] = { "drun", NULL };


static const char *browsercmd[] = { "qutebrowser",     NULL };
static const char *filescmd[] = { "alacritty","-e","lf","~/Documents/",     NULL };
static const char *alttermcmd[] = { "alacritty",     NULL };
static const char *brightnessup[] = { "xbacklight", "-inc", "5",     NULL };
static const char *brightnessdown[] = { "xbacklight", "-dec", "5",     NULL };

static const char *voldown[] = { "amixer", "-q", "set", "Master", "5-",     NULL };
static const char *volup[] = { "amixer", "-q", "set", "Master", "5+",     NULL };

#define DESKTOPCHANGE(K,N) \
    {  MOD4,             K,              change_desktop, {.i = N}}, \
    {  MOD4|ShiftMask,   K,              client_to_desktop, {.i = N}}, 

/* Keybindings */
static key keys[] = {
    /* cycle between windows on desktop (alt+tab) */
    {  MOD4,             XK_j,        next_win,          {NULL}},
    {  MOD4,       XK_k,        prev_win,          {NULL}},
    /* move tiled windows to different positions*/
    {  MOD4,             XK_Down,       move_down,         {NULL}},
    {  MOD4,             XK_Up,         move_up,           {NULL}},
    /* swap the current tiled window with the master */
    {  MOD4,             XK_w,          swap_master,       {NULL}},
    /* maximize toggle for the current window */
    {  MOD4,             XK_f,          maximize,          {NULL}},
    /* float focused window and center it */
    {  MOD4,             XK_p,          popout,            {NULL}},
    /* toggles inverted stacking of slave windows for TILE layout */
    {  MOD4,             XK_i,          invertstack,       {NULL}},
    /* change tiling mode: TILE or EQUAL */
    {  MOD4|SHIFT,       XK_t,          switch_mode,       {.i = TILE}},
    {  MOD4|SHIFT,       XK_e,          switch_mode,       {.i = EQUAL}},
    {  MOD4,			 XK_m,			swap_modes,	   	   {NULL}},
    /* spawn terminal, dmenu, anything you want to */
    {  MOD4,             XK_Return,     spawn,             {.com = termcmd}},
    {  MOD4,             XK_r,          spawn,             {.com = menucmd}},
    
     {  MOD4,       XK_v,     spawn,             {.com = browsercmd}},
     {  MOD4,       XK_s,     spawn,             {.com = alttermcmd}},
     {  MOD4,       XK_t,     spawn,             {.com = filescmd}},
     {  0, XF86MonBrightnessUp,  spawn,             {.com = brightnessup}}, 
     {  0, XF86MonBrightnessDown,  spawn,             {.com = brightnessdown}},      
     {  0, XF86AudioLowerVolume,  spawn,             {.com = voldown}},     
     {  0, XF86AudioRaiseVolume,  spawn,             {.com = volup}},     
    /* quit current window */
    {  MOD4,             XK_c,          killclient,        {NULL}},
    /* desktop selection */
       DESKTOPCHANGE(    XK_1,                             0)
       DESKTOPCHANGE(    XK_2,                             1)
       DESKTOPCHANGE(    XK_3,                             2)
       DESKTOPCHANGE(    XK_4,                             3)
       DESKTOPCHANGE(    XK_5,                             4)
       DESKTOPCHANGE(    XK_6,                             5)
       DESKTOPCHANGE(    XK_7,                             6)
       DESKTOPCHANGE(    XK_7,                             6)
       
    {  MOD4,       XK_Left,          rotate,            {.i = -1}},
    {  MOD4,       XK_Right,          rotate,            {.i = +1}},
    /* exit */
    {  MOD4|CONTROL,     XK_q,          quit,              {.i = 0}},
};

static Button buttons[] = {
    /* move/resize using the mouse */
    {  MOD4,    Button1,     mousemotion,   {.i = MOVE}},
    {  MOD4,    Button3,     mousemotion,   {.i = RESIZE}},
};
#endif
