Olin Feist

C++ script to read CSV file and find weighted means
CSV files must be formated with the following columns(Names dont matter but data must be in that order)
Value | Count | Grid_Id | Depth

If g++ is less than 4.7 use SumProductNoTime. To check do "g++ --version"

To Run script simple:
1. Open terminal and go to directory, then got to src
2 run: "g++ -O2 SumProduct.cpp -o SumProduct" || "g++ -O2 SumProductNoTime.cpp -o SumProductNoTime"
3. run: "./SumProduct" || "./SumProductNoTime"
4. Open weighted means text file


Code explanations:

1.Loop through everyline of csv file, for each line check if gridID is already in table, if yes add current values, if not in table create new row
with grid ID (Seen below)

		gridID	Depth	Count				Table
	1:	103	-240	5------------currenline--->	GridId	SumCount	DepthSum
	2:	103	-230	3			  |-	102	100		-2000
	3:	203	-210	2			  |-	104	50		-200						
	4:	405	-40	2			  |-	203	40		-300
	4:	405	-45	3			  |--->	103	(Add count)	(Add (Count*depth)

2. Loop through table and for each row write gridID and (DepthSum/Sumcount)(Float)
3. Save and output text file




