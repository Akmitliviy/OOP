#include "CExceptions.h"

char const* CExceptions::what() const {
	return "Some of exceptions, I don't know what you want from me!";
}

char const* CBadAllocation::what() const {
	return "Your shit doesn't work cause your compiler is suck in allocating merely few bytes of memory :)";
}

char const* CInputIssue::what() const {
	return "How dare you to enter your shitty wrong input values?! You gonna die for this *sounds of chainsaw*";
}

char const* COutputIssue::what() const {
	return "What?! You're so pathetic you even not able to print some fuckin' text you've written? Idiot";
}

char const* CGetNameOfColumnOutOfRange::what() const {
	return "Moron. There is no such a column your index as big as my dick. That's to much. Or you stupid enough to enter negative number, comparable with size of your stuff in pants?";
}

char const* CGetTypeOfColumnOutOfRange::what() const {
	return "Hey man, I'm with you. No, really, bein imbecile is a heavy burden, and I'll try to help you, you should only ask :)";
}

char const* CGetValueOfColumnOutOfRange::what() const {
	return "Now you come to me and say: \"Code, give me normal result\", but you don't ask with respect.";
}

char const* CZeroColumnsMultiplication::what() const {
	return "You're hopeless fatty clown. Just fuck off.";
}