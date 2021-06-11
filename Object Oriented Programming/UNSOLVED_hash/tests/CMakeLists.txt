add_executable(test_hash_seq test_hash_seq.cpp)
target_link_libraries(test_hash_seq  googletest pthread)

add_test(
  NAME test_hash_seq
  COMMAND test_hash_seq
)