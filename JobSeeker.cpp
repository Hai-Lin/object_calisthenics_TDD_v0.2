#include"JobSeeker.h"

JobSeeker::JobSeeker(Resume* resume) {
	_resume = resume;
}

bool JobSeeker::hasResume() {
	if(_resume != NULL)
		return true;
	if(_resume == NULL)
		return false;
}

