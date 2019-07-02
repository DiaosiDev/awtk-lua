import os
import sys
import platform

#for pc
sys.path.insert(0, '../awtk/')

#for linux-fb
#sys.path.insert(0, '../awtk-linux-fb/')

import awtk_config as awtk

APP_ROOT    = os.path.normpath(os.getcwd())
APP_BIN_DIR = os.path.join(APP_ROOT, 'bin')
APP_LIB_DIR = os.path.join(APP_ROOT, 'lib')
RES_ROOT    = awtk.TK_DEMO_ROOT.replace("\\", "\\\\")
APP_3RD_ROOT = os.path.join(APP_ROOT, '3rd')

os.environ['APP_ROOT'] = APP_ROOT;
os.environ['BIN_DIR'] = APP_BIN_DIR;
os.environ['LIB_DIR'] = APP_LIB_DIR;

APP_LIBS = ['assets']
APP_LIBPATH = [APP_LIB_DIR]
APP_CPPPATH = [APP_3RD_ROOT]
APP_CCFLAGS = '-DRES_ROOT=\"\\\"'+RES_ROOT+'\\\"\" -DLUA_COMPAT_MODULE '

DefaultEnvironment(
  CPPPATH   = APP_CPPPATH + awtk.CPPPATH,
  LINKFLAGS = awtk.LINKFLAGS,
  LIBS      = APP_LIBS + awtk.LIBS,
  LIBPATH   = APP_LIBPATH + awtk.LIBPATH,
  CCFLAGS   = APP_CCFLAGS + awtk.CCFLAGS, 
  OS_SUBSYSTEM_CONSOLE=awtk.OS_SUBSYSTEM_CONSOLE,
  OS_SUBSYSTEM_WINDOWS=awtk.OS_SUBSYSTEM_WINDOWS)

if awtk.OS_NAME != 'Windows':
  DefaultEnvironment(CC=awtk.TOOLS_PREFIX+'gcc',
    CXX=awtk.TOOLS_PREFIX+'g++',
    LD=awtk.TOOLS_PREFIX+'g++',
    AR=awtk.TOOLS_PREFIX+'ar',
    STRIP=awtk.TOOLS_PREFIX+'strip')


SConscript(['3rd/lua/SConscript', 'src/SConscript']);

