#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
int main(int argc, char *argv[])
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "test.lua");
    lua_getglobal(L,"showinfo");
    lua_pcall(L,0,0,0);


    lua_getglobal(L,"lua_add");
    lua_pushinteger(L,1);
    lua_pushinteger(L,5);
    lua_pcall(L,2,1,0);

    printf("lua add function return val is %d \n",lua_tointeger(L,-1));

    lua_close(L);

    return 0;
}
