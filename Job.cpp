#include"Job.h"

Job::Job(JobType jobType) {
	_jobType = jobType;
}

bool Job::isThisJobNeedResume() {
	if(_jobType == ATS) 
		return false;
	if(_jobType == JReq)
		return true;
}
	
