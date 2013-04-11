#include "JobApplicationsManager.h"

JobApplicationsManager::JobApplicationsManager() {
	JobApplications* jobApplications = new JobApplications();
	_jobApplications = jobApplications;
}

bool JobApplicationsManager::canApplyThisJob(JobSeeker* jobSeeker, Job* job) {
	return job->isThisJobNeedResume() and jobSeeker->hasResume() or !job->isThisJobNeedResume();
}

bool JobApplicationsManager::applyJob(JobSeeker* jobSeeker, Job* job, Date* date) {
	if(canApplyThisJob(jobSeeker, job)) {
		JobApplication* jobApplication = new JobApplication(jobSeeker, job, date);
		_jobApplications->addJobApplication(jobApplication);
	}
	return canApplyThisJob(jobSeeker, job);
}

Jobs* JobApplicationsManager::seeAllAppliedJobsBy(JobSeeker* jobSeeker) {
	return _jobApplications->seeAllAppliedJobsBy(jobSeeker);
}

JobSeekers* JobApplicationsManager::jobSeekersWhoAppliedTo(Job* job) {
	return _jobApplications->jobSeekersWhoAppliedTo(job);
}

JobSeekers* JobApplicationsManager::jobSeekersAppliedOn(Date* date) {	
	return _jobApplications->jobSeekersAppliedOn(date);
}
