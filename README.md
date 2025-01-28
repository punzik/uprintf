## Simplified printf alternative

Format specifiers in the string, similar to printf, begin with the `%` symbol. Following this symbol, a type specifier can be included, optionally accompanied by width alignment, an alignment character, and the direction of alignment.

By default, numbers are right-aligned with the `'0'` character, while strings are left-aligned with spaces. To define a custom alignment character, use a single quote (`'`) followed by the desired alignment character before specifying the width.

The width indicator is a signed decimal number that sets the minimum length of the output string. If the string is shorter than this length, the remaining space is filled with the alignment character. If the width is negative, the alignment shifts to the right. For numbers, if no alignment character is specified, they are always right-aligned with `'0'`. Alternatively, the `'*'` character can be used to indicate that the width should be taken from the function argument.

The type specifier may include a `'l'` prefix to denote a 64-bit long integer or a `'u'` prefix to indicate an unsigned number.

Type specifiers:
  - `d`, `i`    Decimal integer.
  - `o`         Octal integer.
  - `b`         Binary integer.
  - `x`         Hexadecimal integer (lowercase).
  - `X`         Hexadecimal integer (uppercase).
  - `c`         Single character.
  - `s`         String. If width is specified, the string is left-aligned.

Example:

```cpp
p("I:+%'=-6i+\n", 10);

Output:
I:+====10+
```

## Простая замена printf

Спецификаторы в форматной строке так же как и в printf начинаются со знака `%`. После этого знака может идти спецификатор типа с опциональным указанием ширины выравнивания, символа для выравнивания и направления выравнивания.

По умолчанию числа выравниваются символом `'0'` по правому краю, а строки пробелом по левому краю. Чтобы задать символ выравниявания, перед указателем ширины нужно поставить одинарную кавычку (`'`) и символ выравнивания.

Далее идет указатель ширины - десятичное число со знаком, обозначающее минимальную длину выводимой строки. Если строка получается меньше этого числа, недостающая длина добирается символами выравнивания. Если ширина указана в виде отрицательного числа, то выравнивание выполняется по правому краю. Если для числа не указан символ выравнивания, то оно всегда выравнивается символом `'0'` по правому краю. Вместо числа может стоять символ `'*'`, говоряший о том, что ширину нужно брать из аргумента функции.

Спецификатор типа может иметь префикс `'l'`, обозначающий длинное целое (64 бита) и/или префикс `'u'`, обозначающий беззнаковое число.

Спецификаторы типа:
  - `d`, `i`    Десятичное целое.
  - `o`         Восьмиричное целое.
  - `b`         Двоичное целое.
  - `x`         Шестнадцатиричное целое (строчными).
  - `X`         Шестнадцатиричное целое (прописные).
  - `c`         Символ.
  - `s`         Строка. Если указана ширина, то выравнивание по левому краю.

Пример:

```
p("I:+%'=-6i+\n", 10);

Вывод:
I:+====10+
```
