
FILE_EXE_NAME = run
FILE_TEXT_1_NAME = fileText1.log
FILE_TEXT_2_NAME = fileText2.log
FILE_TEXT_3_NAME = fileText3.log
FILE_TEXT_4_NAME = fileText4.log

all:
	g++ main.cpp -o $(FILE_EXE_NAME)
	touch $(FILE_TEXT_1_NAME) $(FILE_TEXT_2_NAME) $(FILE_TEXT_3_NAME) $(FILE_TEXT_4_NAME)

	echo "Hoang Sa - Truong Sa la cua Viet Nam" > $(FILE_TEXT_1_NAME)
	echo "Viet Nam vo dich!!!" > $(FILE_TEXT_2_NAME)
	echo "Everything in linux is a file T.T" > $(FILE_TEXT_3_NAME)
	echo "ADN-Linux" > $(FILE_TEXT_4_NAME)
clean:
	rm -rf $(FILE_EXE_NAME) $(FILE_TEXT_1_NAME) $(FILE_TEXT_2_NAME) $(FILE_TEXT_3_NAME) $(FILE_TEXT_4_NAME)