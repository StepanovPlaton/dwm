/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */

static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */

static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */

static const int vertpad            = 5;       /* vertical padding of bar */
static const int sidepad            = 5;       /* horizontal padding of bar */
static const int horizpadbar        = 0;        /* horizontal padding for statusbar */
static const int vertpadbar         = 10;        /* vertical padding for statusbar */

static const int statusvertpadbar   = 4;
static const int systrayvertpad     = 2;

static const unsigned int gappih    = 5;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;       /* vert inner gap between windows */
static const unsigned int gappoh    = 5;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 5;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

static const char *fonts[]          = { "Liberation Sans:style=Bold:size=10:antialias=true:autohint=true", "Font Awesome 6 Free Solid:style=Solid:size=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "CodeNewRoman Nerd Font Mono:size=16:antialias=true:autohint=true";

static const char col_gray[]        = "#151515";//"#3b3b3b";
static const char col_white[]       = "#cccccc";//"#ffffff";
static const char col_yellow[]      = "#e7c547";//"#ffd700";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_white, col_gray, col_gray },
	[SchemeSel]  = { col_yellow, col_gray,  col_yellow },
};
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
 	{ 
		"st-256color",				// class
		NULL,						// instance
		NULL,						// title
		NULL,						// tags mask
		0,							// isfloating
		1,							// isterminal
		0,							// noswallow
		-1,							// monitor
		0,0,0,0,					// float x,y,w,h
		-1							// floatborderpx
	},
 	{ 
		"TelegramDesktop",			// class
		NULL,						// instance
		NULL,						// title
		NULL,						// tags mask
		1,							// isfloating
		0,							// isterminal
		0,							// noswallow
		-1,							// monitor
		1400,  50, 425, 600,        // float x,y,w,h 
		-1							// floatborderpx
	},
 	{ 
		"transmission",				// class
		NULL,						// instance
		NULL,						// title
		NULL,						// tags mask
		1,							// isfloating
		0,							// isterminal
		0,							// noswallow
		-1,							// monitor
		1050, 680, 800, 350,        // float x,y,w,h 
		-1							// floatborderpx
	},
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
// dmenu_run -x 5 -y 5 -z 1270 -m 0 -fn 'CodeNewRoman Nerd Font Mono:size=16:antialias=true:autohint=true' -nb '#151515' -nf '#cccccc' -sb '#151515' -sf '#e7c547'
static const char *dmenucmd[] = { "dmenu_run", "-x", "5", "-y", "5", "-z", "1270", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray, "-nf", col_white, "-sb", col_gray, "-sf", col_yellow, NULL };

static const char *termcmd[]  = { "st", NULL };

static const char *open_transmission_qt[] = { "/home/dwarf/.scripts/start_transmission_qt.sh", NULL };
static const char *open_telegram[] = { "telegram-desktop", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_t,      spawn,          {.v = open_transmission_qt } },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = open_telegram } },

	{ MODKEY,                       XK_o,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
 	/* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
 	/* { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } }, */
 	/* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
 	/* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
 	/* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
 	/* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
 	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
 	/* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
 	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
 	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
 	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
 	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
 	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
 	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
 	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_q,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
 	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	/* { MODKEY|ShiftMask,             XK_q,      quit,           {0} }, */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

