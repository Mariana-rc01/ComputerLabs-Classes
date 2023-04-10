module MiniTeste_Spec where

import Test.HUnit
import MiniTeste

testes = TestLabel "MiniTeste" $ test ["f Ola" ~: "Ola" ~=? f "Ola"
                                     , "f String vazia " ~: "" ~=? (f "")
                                     , "f O12l34a810" ~: "Ola" ~=? f "O12l34a810"]