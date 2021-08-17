# 1
grep '^[0-9]' sample

# 2
grep '^[0-9a-fA-F]' sample

# 3
grep '^[0-9]\{3\}$' sample

# 4
grep '^[0-9a-fA-F ]\+$' sample

# 5
grep '^[a-zA-Z ]\+$' sample

# 6
grep '(217) [0-9]\{3\}-[0-9]\{4\}' sample

# 7
grep '\((312)\|(708)\) [0-9]\{3\}-[0-9]\{4\}' sample

# 8
grep '\.\+' sample

# 9
grep '\(\(25[0-5]\|2[0-4][0-9]\|[01]\?[0-9][0-9]\?\)\(\.\|\s\|$\)\)\{4\}' sample

# 10
grep '[a-zA-Z0-9+_.-]\+@[a-zA-Z0-9.-]\+' sample

# 11
grep '".\+"' sample

# 12
grep '$[0-9]\{1,\}\.[0-9]\{2\}' sample

# 13
grep '^.\{11,\}$' sample

# 14
grep '^.\{,9\}$' sample

# 15
grep -o '\<b[a-z]\{3\}da[a-z]\>' sample

# 16
grep -o '\<[a-z]*qi[a-z]*\>' sample

# 17
grep -o '\<[A-Z].*qi.*\>' sample

# 18
grep -o '\<.\{22,23\}\>' sample

# 19
grep -o '\<.*a[^aeiou]*e[^aeiou]*i[^aeiou]*o[^aeiou]*u.*\>' sample

