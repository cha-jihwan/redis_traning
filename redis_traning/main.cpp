
#include <iostream>
#include "../hiredis/CRedisConn.h"

/*
링커 >일반 >추가 라이브러리 디렉토리 // hiredis.lib가 있는 폴더
#pragma comment(lib, "hiredis.lib") // 위에 설정을 해서 lib 불러오기가 가능.

C/C++ > 일반 > 추가 포함 디렉터리 // header가 있는 경로.
*/
#pragma comment(lib, "hiredis.lib")
int main()
{
	RedisCpp::CRedisConn con;

	std::string value;
	uint32_t retval = 0;

	if ( !con.connect( "127.0.0.1", 6379 ) )
	{
		std::cout << "connect error " << con.getErrorStr() << std::endl;
		return -1;
	}
	else
	{
		std::cout << "connect success !!!" << std::endl;
	}


	if ( con.get( "test02", value ) )
	{
		printf( "test02 - %s", value.c_str() );
		con.del( "test02", retval );
	}
	else
	{
		std::cout << "test02 - ???" << std::endl;
		con.set( "test02", "llll", retval );
	}

}