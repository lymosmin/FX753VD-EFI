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


9.  debug boot arg:
  -v keepsyms=1 -dbgenhdbg -dbgenhbeta -dbgenhiolog debug=0x100 msgbuf=1048576  -hbfxdbg -no_compat_check ipc_control_port_options=0 -dbglog

10. release boot arg
  -no_compat_check

11. disable mount disk part
  sudo vi /etc/fstab # add those
  UUID=0C24C632-AB0B-4C1C-8FE1-4CC55415DE6C none ntfs noauto
  UUID=AD98E042-0BD2-44E2-89B6-A54D9EA61C45 none ntfs noauto
  UUID=46575D94-D7C8-4D96-9752-1D1597F530D9 none ntfs noauto
  UUID=E61BD1E6-6C5F-4553-8ABC-90BF93665C4E none ntfs noauto
  UUID=516E5D12-439D-4757-8D64-9951FA38B30D none ntfs noauto

12. boot error message: 
  [  150.130098]: AppleSMCFamily::handleSMCResult ERROR in smcReadKeyMMIO.  TH0x kSMCBadArgumentError(0x89)

13. boot error message:
  [ 1183.112311]: IG:: get_gstate:2446 (state=15, fPowerStatesEnable=1)

