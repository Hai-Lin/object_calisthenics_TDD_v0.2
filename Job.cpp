#include"Job.h"

Job::Job(Recruiter* recruiter) {
	_postByRecruiter = recruiter;
}

bool Job::isPostedBy(Recruiter* recruiter) {
	return recruiter == _postByRecruiter;
}
	
Jobs::Jobs() {
	vector<Job*> jobs;
	_jobs = jobs;
}

void Jobs::addJob(Job* job) {
	_jobs.push_back(job);
}

Job* Jobs::atIndex(int index) {
	if(index >= _jobs.size()) {
		cout<<"Index bigger than jobs size, exit!"<<endl;
		exit(-1);
	}
	return _jobs[index];
}

int Jobs::sizeOf() {
	return _jobs.size();
}

