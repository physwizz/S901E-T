#ifndef __SEC_QC_UPLOAD_CAUSE_H__
#define __SEC_QC_UPLOAD_CAUSE_H__

enum {
	UPLOAD_CAUSE_INIT = 0xCAFEBABE,
/* ++ KP : 0xC8xx_xxxx ++ */
	UPLOAD_CAUSE_KERNEL_PANIC = 0xC8000000,
	UPLOAD_CAUSE_USER_FAULT,
	UPLOAD_CAUSE_HSIC_DISCONNECTED,
	UPLOAD_CAUSE_BUS_HANG,
	UPLOAD_CAUSE_PF_WD_BITE,
	UPLOAD_CAUSE_PF_WD_INIT_FAIL,
	UPLOAD_CAUSE_PF_WD_RESTART_FAIL,
	UPLOAD_CAUSE_PF_WD_KICK_FAIL,
/* ++ SubSystem : 0xC8_5353_xx ++ */
	UPLOAD_CAUSE_SS_START = 0xC8535300,
	UPLOAD_CAUSE_CP_ERROR_FATAL = UPLOAD_CAUSE_SS_START,
	UPLOAD_CAUSE_MDM_ERROR_FATAL,
	UPLOAD_CAUSE_MDM_CRITICAL_FATAL,
	UPLOAD_CAUSE_MODEM_RST_ERR,
	UPLOAD_CAUSE_ADSP_ERROR_FATAL,
	UPLOAD_CAUSE_SLPI_ERROR_FATAL, /* 5 */
	UPLOAD_CAUSE_SPSS_ERROR_FATAL,
	UPLOAD_CAUSE_NPU_ERROR_FATAL,
	UPLOAD_CAUSE_CDSP_ERROR_FATAL,
	UPLOAD_CAUSE_SUBSYS_IF_TIMEOUT,
	UPLOAD_CAUSE_RIVA_RST_ERR, /* A */
	UPLOAD_CAUSE_LPASS_RST_ERR,
	UPLOAD_CAUSE_DSPS_RST_ERR,
	UPLOAD_CAUSE_PERIPHERAL_ERR,
	UPLOAD_CAUSE_SS_END = UPLOAD_CAUSE_PERIPHERAL_ERR,
/* -- SubSystem : 0xC8_5353_xx -- */
/* ++ Quest : 0xC8_5153_xx ++ */
	UPLOAD_CAUSE_QUEST_START = 0xC8515300,
	UPLOAD_CAUSE_QUEST_CRYPTO = UPLOAD_CAUSE_QUEST_START,
	UPLOAD_CAUSE_QUEST_ICACHE,
	UPLOAD_CAUSE_QUEST_CACHECOHERENCY,
	UPLOAD_CAUSE_QUEST_SUSPEND,
	UPLOAD_CAUSE_QUEST_VDDMIN,
	UPLOAD_CAUSE_QUEST_QMESADDR, /* 5 */
	UPLOAD_CAUSE_QUEST_QMESACACHE,
	UPLOAD_CAUSE_QUEST_PMIC,
	UPLOAD_CAUSE_QUEST_UFS,
	UPLOAD_CAUSE_QUEST_SDCARD,
	UPLOAD_CAUSE_QUEST_SENSOR, /* A */
	UPLOAD_CAUSE_QUEST_SENSORPROBE,
	UPLOAD_CAUSE_QUEST_NATURESCENE,
	UPLOAD_CAUSE_QUEST_A75G,
	UPLOAD_CAUSE_QUEST_Q65G,
	UPLOAD_CAUSE_QUEST_THERMAL, /* F */
	UPLOAD_CAUSE_QUEST_QDAF_FAIL, /* 10 */
	UPLOAD_CAUSE_QUEST_FAIL,
	UPLOAD_CAUSE_QUEST_DDR_TEST_MAIN,
	UPLOAD_CAUSE_QUEST_DDR_TEST_CAL,
	UPLOAD_CAUSE_QUEST_DDR_TEST_SMD,
	UPLOAD_CAUSE_SOD_RESULT,
	UPLOAD_CAUSE_QUEST_ZIP_UNZIP,
	UPLOAD_CAUSE_DRAM_SCAN,
	UPLOAD_CAUSE_QUEST_AOSSTHERMALDIFF,
	UPLOAD_CAUSE_QUEST_STRESSAPPTEST,
	UPLOAD_CAUSE_SUEFI_SWT_UPLOAD,
	UPLOAD_CAUSE_QUEFI_SWT_UPLOAD,
	UPLOAD_CAUSE_QUEST_END = UPLOAD_CAUSE_QUEFI_SWT_UPLOAD,
/* --Quest : 0xC8_5153_xx -- */
/* -- KP : 0xC8xx_xxxx -- */
/* ++ TP ++ */
	UPLOAD_CAUSE_POWER_THERMAL_RESET = 0x54500000,
/* -- TP -- */
/* ++ DP ++ */
	UPLOAD_CAUSE_NON_SECURE_WDOG_BARK = 0x44500000,
/* -- DP -- */
/* ++ WP ++ */
	UPLOAD_CAUSE_NON_SECURE_WDOG_BITE = 0x57500000,
	UPLOAD_CAUSE_SECURE_WDOG_BITE,
/* -- WP -- */
/* ++ MP ++ */
/* Intended reset (MP) 0x4D50_xxxx */
	UPLOAD_CAUSE_MP_START = 0x4D500000,
	UPLOAD_CAUSE_POWER_LONG_PRESS = UPLOAD_CAUSE_MP_START,
	UPLOAD_CAUSE_FORCED_UPLOAD,
	UPLOAD_CAUSE_USER_FORCED_UPLOAD,
	UPLOAD_CAUSE_MP_END = UPLOAD_CAUSE_USER_FORCED_UPLOAD,
/* -- MP -- */
/* ++ PP ++ */
	UPLOAD_CAUSE_EDL_FORCED_UPLOAD = 0x50500000,
	UPLOAD_CAUSE_PM_OCP,
/* -- PP -- */
/* ++ SP -- */
	UPLOAD_CAUSE_SMPL = 0x53500000,
/* -- SP -- */
};

#if IS_ENABLED(CONFIG_SEC_QC_UPLOAD_CAUSE)
extern void sec_qc_upldc_write_cause(unsigned int type);
extern unsigned int sec_qc_upldc_read_cause(void);

extern void sec_qc_upldc_type_to_cause(unsigned int type, char *cause, size_t len);
#else
static inline void sec_qc_upldc_write_cause(unsigned int type) {}
static inline unsigned int sec_qc_upldc_read_cause(void) { return UPLOAD_CAUSE_INIT; }

static inline void sec_qc_upldc_type_to_cause(unsigned int type, char *cause, size_t len) {}
#endif

#endif /* __SEC_QC_UPLOAD_CAUSE_H__ */