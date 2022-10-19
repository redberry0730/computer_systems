INPUT="32 F
100 C
23 yd
1 yd
0 yd
17 m
1 m
0 m
57 lb
1 lb
0 lb
59 kg
1 kg
0 kg
0.0 c
288.3712 KG
q
"

OUTPUT="Please enter a temperature, length, or mass, as a decimal numeral,
followed by a unit to be converted:
- F, lb, yd, C, kg, or m
Enter \"q\" to quit.
> 32.00 F = 0.00 C
> 100.00 C = 212.00 F
> 23.00 yd = 21.03 m
> 1.00 yd = 0.91 m
> 0.00 yd = 0.00 m
> 17.00 m = 18.59 yd
> 1.00 m = 1.09 yd
> 0.00 m = 0.00 yd
> 57.00 lb = 25.85 kg
> 1.00 lb = 0.45 kg
> 0.00 lb = 0.00 kg
> 59.00 kg = 130.07 lb
> 1.00 kg = 2.20 lb
> 0.00 kg = 0.00 lb
> Invalid unit: c
> 288.37 kg = 635.75 lb
> "

echo "Compiling ..."
gcc -std=c99 -Wall -Werror converter.c -o converter
echo "Diffing ..."
echo "$INPUT" > XYZinput.txt
echo "$OUTPUT\n" > XYZexpected.txt
./converter < XYZinput.txt > XYZoutput.txt
echo "\n" >> XYZoutput.txt
DIFF=$(diff XYZexpected.txt XYZoutput.txt)
if [ "$DIFF" != "" ]
then
    echo "\nXXXXXXXX UNEXPEXTED OUTPUT: XXXXXXXX\n"
    echo "$DIFF\n"
else
    echo "\n======== CORRECT ========\n"
fi
rm -f XYZoutput.txt XYZinput.txt XYZexpected.txt
