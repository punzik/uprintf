## Simple printf replacement

The conversion specificator in the format string as in printf begins
with a % character. This character can be followed by a type specifier
with an optional of the padding width, padding character and direction
of the padding.

By default numbers are right-justified with '0' and strings are
left-justified with a space. To specify an alignment character precede
the width indicator with a single quote (') and an alignment
character.

Next comes the width indicator - a signed decimal number indicating
the minimum length of the output string. If the string is less than
this number, the missing length is taken up by alignment
characters. If the width is specified as a negative number, the
alignment is right-justified. If no alignment character is specified
for a number, it is always right-justified with '0'. Instead of a
number for width you can be use a '*' symbol, which means that the
width must be taken from the function argument.

The type specifier can be prefixed with 'l' for a long integer (64
bits) and / or prefix 'u' for an unsigned number.

Type specifiers:
  - d, i Decimal integer.
  - o Octal integer.
  - b Binary integer.
  - x Hexadecimal integer (lowercase).
  - X Hexadecimal integer (uppercase).
  - c Symbol.
  - s String. If width is specified, then left alignment.

Example:

```
p ("I: +% '= - 6i + \ n", 10);

Output:
I: + ==== 10+
```

## Простая замена printf

Спецификаторы в форматной строке так же как и в printf начинаются со
знака %. После этого знака может идти спецификатор типа с опциональным
указанием ширины выравнивания, символа для выравнивания и направления
выравнивания.

По умолчанию числа выравниваются символом '0' по правому краю, а
строки пробелом по левому краю. Чтобы задать символ выравниявания,
перед указателем ширины нужно поставить одинарную кавычку (') и символ
выравнивания.

Далее идет указатель ширины - десятичное число со знаком, обозначающее
минимальную длину выводимой строки. Если строка получается меньше
этого числа, недостающая длина добирается символами выравнивания. Если
ширина указана в виде отрицательного числа, то выравнивание
выполняется по правому краю. Если для числа не указан символ
выравнивания, то оно всегда выравнивается символом '0' по правому
краю. Вместо числа может стоять символ '*', говоряший о том, что
ширину нужно брать из аргумента функции.

Спецификатор типа может иметь префикс 'l', обозначающий длинное целое
(64 бита) и/или префикс 'u', обозначающий беззнаковое число.

Спецификаторы типа:
  - d, i      Десятичное целое.
  - o         Восьмиричное целое.
  - b         Двоичное целое.
  - x         Шестнадцатиричное целое (строчными).
  - X         Шестнадцатиричное целое (прописные).
  - c         Символ.
  - s         Строка. Если указана ширина, то выравнивание по левому краю.

Пример:

```
p("I:+%'=-6i+\n", 10);

Вывод:
I:+====10+
```
