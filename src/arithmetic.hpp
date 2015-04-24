namespace aalgo
{

// Return the number of carry operations required to add the two given integers from right to left as would be taught in primary school to children.  This is from chapter 2 of the Algorithm Design Manual.  This is UVa Programming Challenge 10035.
unsigned carryOpertions(unsigned a, unsigned b);

// Return the number of digits in the given integer. 0 is considered to have 1 digit.
unsigned numberOfDigits(unsigned a);

// Return the digit at position i of the given integer a where the first position in an integer is the right most position starting at index i = 1.  An exception will be thrown if i is larger than the total number of digits in a.
unsigned digitAt(unsigned a, unsigned i);

} // aalgo

