#include"utility.h"
class Job;
class JobSeeker {
	private:
		vector<Job*> _savedJobs;
	public:
		void saveJob(Job* );
};
