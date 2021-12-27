protoc.exe --grpc_out=./build --plugin=protoc-gen-grpc=grpc_cpp_plugin.exe Algorithm_FileProcess.proto
protoc.exe --cpp_out=./build Algorithm_FileProcess.proto

pause