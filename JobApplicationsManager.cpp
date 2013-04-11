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

int JobApplicationsManager::getApplicationNumber(Job* job) {
	return _jobApplications->getApplicationNumber(job);
}

int JobApplicationsManager::getApplicationNumber(Recruiter* recruiter) {
	return _jobApplications->getApplicationNumber(recruiter);
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

JobSeekers* JobApplicationsManager::jobSeekersAppliedToOn(Job* job, Date* date) {
	return _jobApplications->jobSeekersAppliedToOn(job, date);
}

JobSeekers* JobApplicationsManager::jobSeekersAppliedToOnPostBy(Job* job, Date* date, Recruiter* recruiter) {
	return _jobApplications->jobSeekersAppliedToOnPostBy(job, date, recruiter);
}
