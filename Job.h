#include"utility.h"

class Job {

};

class JobCollection {
	private:
		vector<Job*> _jobs;
	public:
		JobCollection();
		void addJobToCollection(Job* );
		Job* atIndex(int index);
};
