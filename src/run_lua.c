#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>

#include "awtk.h"
#include "demos/resource.h"

extern void luaL_openawtk(lua_State* L);

int main(int argc, char* argv[]) {
  lua_State* L = luaL_newstate();
  const char* lua_file = argc == 2 ? argv[1] : "./demo2.lua";

  luaL_openlibs(L);
  luaL_openawtk(L);

  tk_init(320, 480);
  resource_init();

  if (luaL_dofile(L, lua_file)) {
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    lua_pop(L, 1);
  } else {
    tk_run();
  }

  lua_close(L);

  return 0;
}
