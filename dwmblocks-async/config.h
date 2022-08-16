#define CMDLENGTH 100
#define DELIMITER "   "
#define CLICKABLE_BLOCKS

const Block blocks[] = {
	BLOCK("dwmba_lan.block",        10,      0),
	BLOCK("dwmba_disk.block",       3*60*60, 0),
	BLOCK("dwmba_cpu.block",        10,      0),
	BLOCK("dwmba_mem_p.block",      10,      0),
	BLOCK("dwmba_weather.block",    60*60,   0),
	BLOCK("dwmba_date.block",       30,      0),
};
