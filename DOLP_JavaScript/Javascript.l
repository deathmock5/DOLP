$FILE js

/* Parser Tokens */
#Comment:	(\/\/.*\n)
#String:	(['\"].*['\"])
#Operator:	([\+\-\/%^\*]=|[\+\-\/%^\*]{1,2})
#WhiteSpace:	( )
#Number:	([0-9]+)
#Binary:	()
#Punctuation:	([\[\]{}\(\)<>;,=:]{1})
#Words:	()
#Symbols:	()