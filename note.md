1. 查看lilu DBGLOG 日志： sudo dmesg | grep -i "DBG"

2. 输出日志 / 查看日志 
  log show --style syslog --predicate 'process == "kernel"' --last 10m > log1.log
  log stream --info --debug --predicate 'eventMessage contains "ACPIDebug"'

3. 启动参数： 
  -v keepsyms=1 -dbgenhdbg -dbgenhbeta -dbgenhiolog debug=0x12a msgbuf=1048576 -asussmcdbg acpi_layer=0x8 acpi_level=0x2 -no_compat_check amfi=0x80 -brkeysdbg ipc_control_port_options=0 -revbeta revpatch=sbvmm -lilubetaall

4. 查看睡眠唤醒日志：
  pmset -g log | grep -E "Wake from"

5. apple alc layout-id
  16 29 其中29比较适合

6. 触控板 强制使用轮询模式： (能驱动)
  boot-arg加上 -vi2c-force-polling
  需要以下驱动：
  VoodooI2C.kext
  VoodooI2C.kext/Contents/PlugIns/VoodooI2CServices.kext
  VoodooI2C.kext/Contents/PlugIns/VoodooInput.kext
  VoodooI2C.kext/Contents/PlugIns/VoodooGPIO.kext
  VoodooI2CHID.kext

7. 触控板 使用轮询模式： (能驱动)
  加入补丁：SSDT-TPD1-POLL.aml

8. 触控板 GPIO中断模式还未成功


  

[  258.457525]: process_is_plugin_host: running binary "sh" in keys-off mode due to identity: com.apple.shprocess_is_plugin_host: running binary "bash" in keys-off mode due to identity: com.apple.bashAsusSMC       als: @ (DBG) refreshALS lux 300

[
  {
    "value": "1",
    "usagePage": "65329 (0xff31)",
    "usage": "32 (0x0020)"
  },
  {
    "value": "1",
    "usagePage": "65329 (0xff31)",
    "usage": "32 (0x0020)"
  },
  {
    "value": "32",
    "usagePage": "65329 (0xff31)",
    "usage": "-1 (0xffffffff)"
  },
  {
    "value": "32",
    "usagePage": "65329 (0xff31)",
    "usage": "-1 (0xffffffff)"
  },
  {
    "value": "0",
    "usagePage": "65329 (0xff31)",
    "usage": "32 (0x0020)"
  },
  {
    "value": "0",
    "usagePage": "65329 (0xff31)",
    "usage": "32 (0x0020)"
  },
  {
    "value": "0",
    "usagePage": "65329 (0xff31)",
    "usage": "-1 (0xffffffff)"
  },
  {
    "value": "0",
    "usagePage": "65329 (0xff31)",
    "usage": "-1 (0xffffffff)"
  },
  {
    "value": "1",
    "usagePage": "65329 (0xff31)",
    "usage": "16 (0x0010)"
  },
  {
    "value": "1",
    "usagePage": "65329 (0xff31)",
    "usage": "16 (0x0010)"
  },
  {
    "value": "16",
    "usagePage": "65329 (0xff31)",
    "usage": "-1 (0xffffffff)"
  },
  {
    "value": "16",
    "usagePage": "65329 (0xff31)",
    "usage": "-1 (0xffffffff)"
  },
  {
    "value": "0",
    "usagePage": "65329 (0xff31)",
    "usage": "16 (0x0010)"
  },
  {
    "value": "0",
    "usagePage": "65329 (0xff31)",
    "usage": "16 (0x0010)"
  },
  {
    "value": "0",
    "usagePage": "65329 (0xff31)",
    "usage": "-1 (0xffffffff)"
  },
  {
    "value": "0",
    "usagePage": "65329 (0xff31)",
    "usage": "-1 (0xffffffff)"
  }
]