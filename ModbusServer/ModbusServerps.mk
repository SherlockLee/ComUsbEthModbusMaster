
ModbusServerps.dll: dlldata.obj ModbusServer_p.obj ModbusServer_i.obj
	link /dll /out:ModbusServerps.dll /def:ModbusServerps.def /entry:DllMain dlldata.obj ModbusServer_p.obj ModbusServer_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del ModbusServerps.dll
	@del ModbusServerps.lib
	@del ModbusServerps.exp
	@del dlldata.obj
	@del ModbusServer_p.obj
	@del ModbusServer_i.obj
