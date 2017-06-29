module Codewars.Parentheses where

replace :: Eq a => [a] -> [a] -> [a] -> [a]
replace needle replacement haystack
  = case begins haystack needle of
      Just remains -> replacement ++ remains
      Nothing      -> case haystack of
        []     -> []
        x : xs -> x : replace needle replacement xs
--

begins :: Eq a => [a] -> [a] -> Maybe [a]
begins haystack []                = Just haystack
begins (x : xs) (y : ys) | x == y = begins xs ys
begins _        _                 = Nothing

validBraces :: String -> Bool
validBraces [] = True
validBraces xs = not (xs == exes) && validBraces exes
            where exes = replace "()" [] xs
--

validParentheses :: String -> Bool
validParentheses = validBraces
