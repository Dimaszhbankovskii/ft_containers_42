#!/bin/bash

FILE_RESULT_STD_VECTOR="result_std_vector.log"
FILE_RESULT_FT_VECTOR="result_ft_vector.log"

./std_vector > $FILE_RESULT_STD_VECTOR
./ft_vector > $FILE_RESULT_FT_VECTOR

diff $FILE_RESULT_STD_VECTOR $FILE_RESULT_FT_VECTOR