all:
	g++ proto-write.cc test.pb.cc -lprotobuf -o proto-write
	g++ proto-read.cc test.pb.cc -lprotobuf -o proto-read 
clean:
	rm -rf proto-write proto-read
