#include "savedjobtest.h"

TEST(JobApplication, createJobApplication) {
	Date* date;
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	Resume* resume = new Resume();
	JobApplication(jobSeekerWithResume, atsJob, date);
}

TEST(GetApplicationNumberByJob, getJobApplicationByJob) {
	Recruiter* recruiter = new Recruiter();
	JobsManager* jobsManager = new JobsManager();
	JobApplicationsManager* jobApplicationsManager = new JobApplicationsManager();
	Job* atsJob = new ATSJob(recruiter);
	jobsManager->postJob(atsJob);
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Date* date;
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, atsJob, date));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, atsJob, date));
	EXPECT_EQ(2, jobApplicationsManager->getApplicationNumber(atsJob)); 
}

TEST(GetApplicationNumberByRecruiter, getJobApplicationByRecruiter) {
	Recruiter* recruiter = new Recruiter();
	JobsManager* jobsManager = new JobsManager();
	JobApplicationsManager* jobApplicationsManager = new JobApplicationsManager();
	Job* atsJob = new ATSJob(recruiter);
	jobsManager->postJob(atsJob);
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Date* date;
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, atsJob, date));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, atsJob, date));
	EXPECT_EQ(2, jobApplicationsManager->getApplicationNumber(recruiter)); 
}

