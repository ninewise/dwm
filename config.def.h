/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gap pixel of frames */
static const unsigned int snap      = 32;       /* snap pixel */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

static const Rule rules[] = {0}; // {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                       instance  title  isfloating */
// };

/* layout(s) */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	high,    /* first entry is default */
	wide,
	NULL,    /* no layout function means floating behavior */
	monocle,
};

/* key definitions */
#define MODKEY Mod4Mask

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", "-e", "dvtm", NULL };
static const char *dtimecmd[] = { "show", "date", "+%F %I:%M", NULL };
static const char *battcmd[]  = { "show", "acpi", "-b", NULL };
static const char *passcmd[]  = { "xdopass", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Return, spawnloud,      {.v = termcmd } },
	{ MODKEY,                       XK_t,      spawnloud,      {.v = termcmd } },
	{ MODKEY,                       XK_r,      spawnsilent,    {.v = dmenucmd } },
	{ MODKEY,                       XK_d,      spawnsilent,    {.v = dtimecmd } },
	{ MODKEY,                       XK_b,      spawnsilent,    {.v = battcmd } },
	{ MODKEY,                       XK_p,      spawnsilent,    {.v = passcmd } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_n,      focusfrm,       {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_n,      focusfrm,       {.ui = 1 } },
	{ MODKEY,                       XK_s,      splitfrm,       {0} },
	{ MODKEY|ShiftMask,             XK_s,      mergefrm,       {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_h,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

