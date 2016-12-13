PROGRAM= tests.exe

all:: $(PROGRAM)

$(PROGRAM): 
	g++ -std=c++11 -maes -mavx -I../../openssl-1.0.2j/include  -I../../boost_1_60_0 -I../install/include -o tests.exe tests.cpp interactiveMidProtocolsTests.cpp ../scapi.a -ldl -lpthread -L../install/lib -L../../boost_1_60_0/stage/lib ../../openssl-1.0.2j/libcrypto.a -lboost_system -lntl -lgmp -lblake2 -lssl

tests:: all
	$(Program)

clean::
	rm tests.exe



