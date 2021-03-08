
#include <iostream>
#include "../hiredis/CRedisConn.h"

/*
��Ŀ >�Ϲ� >�߰� ���̺귯�� ���丮 // hiredis.lib�� �ִ� ����
#pragma comment(lib, "hiredis.lib") // ���� ������ �ؼ� lib �ҷ����Ⱑ ����.

C/C++ > �Ϲ� > �߰� ���� ���͸� // header�� �ִ� ���.
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