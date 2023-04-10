{-|
Module : MiniTeste
Description : Módulo Haskell contendo a resolução do exercício 2 do MiniTeste
Copyright : Mariana Rocha <a90817@alunos.uminho.pt>

Este módulo contém a resolução do exercício 2 do MiniTeste realizado no dia 24 de outubro de 2022.
-}
module MiniTeste where

{-| A função 'f' recebe como argumento uma string __s__ e devolve __s__ sem a ocorrência de dígitos.
Para tal acontecer, 'f' verifica recursivamente se cada caracter é um dígito.

A função poderia ser definida da seguinte forma:

@
f :: String -> String
f [] = []
f (h:t) = if elem h ['0'..'9'] then f t else h:f t
@

== Exemplos de utilização:

>>> f "Ola"
"Ola"

>>> f "1234"
""

>>> f "O12l34a810"
"Ola"
-}

f :: String -> String
f [] = []
f (h:t) = if elem h ['0'..'9'] then f t else h:f t