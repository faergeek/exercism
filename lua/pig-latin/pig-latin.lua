return function(phrase)
	return phrase:gsub("%a+", function(word)
		if word:match("^[aeiou]") or word:match("^xr") or word:match("^yt") then
			return word .. "ay"
		elseif word:match("^rh") then
			return word:gsub("^(rh)(%a+)", "%2%1ay")
		elseif word:match("^sch") then
			return word:gsub("^(sch)(%a+)", "%2%1ay")
		elseif word:match("^ch") then
			return word:gsub("^(ch)(%a+)", "%2%1ay")
		elseif word:match("^qu") then
			return word:gsub("^(qu)(%a+)", "%2%1ay")
		elseif word:match("^thr") then
			return word:gsub("^(thr)(%a+)", "%2%1ay")
		elseif word:match("^th") then
			return word:gsub("^(th)(%a+)", "%2%1ay")
		elseif word:match("^[^aeiou]qu") then
			return word:gsub("^([^aeiou]qu)(%a+)", "%2%1ay")
		elseif word:match("^[^aeiou]") then
			return word:gsub("^([^aeiou])(%a+)", "%2%1ay")
		else
			return word
		end
	end)
end
