#include"utility.h"

class Job {
	private:
		JobType _jobType;
	public:
		Job(JobType);
		bool isThisJobNeedResume();
};

