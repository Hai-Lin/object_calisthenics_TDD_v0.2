#include "jobseekertest.h"

TEST(JobSeekerHaveResume, haveResumeTest) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	EXPECT_TRUE(jobSeekerWithResume->hasResume());
	EXPECT_FALSE(jobSeekerWithoutResume->hasResume());
}

TEST(JobSeekersCanApplyJob, applyOneJob) {
	Date* date;
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	JobApplicationsManager* jobApplicationsManager = new JobApplicationsManager();
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, atsJob, date));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, JReqJob, date));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, atsJob, date));
	EXPECT_FALSE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, JReqJob, date));
	Jobs* jobs = jobApplicationsManager->seeAllAppliedJobsBy(jobSeekerWithResume);
	EXPECT_EQ(jobs->atIndex(0), atsJob);
	EXPECT_EQ(jobs->atIndex(1), JReqJob);
}

TEST(JobSeekersCanSaveJob, savejob) {
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	SavedJobsManager* savedJobsManager = new SavedJobsManager();
	savedJobsManager->saveJob(jobSeekerWithResume, atsJob);
	savedJobsManager->saveJob(jobSeekerWithResume, JReqJob);
	savedJobsManager->saveJob(jobSeekerWithoutResume, JReqJob);
	savedJobsManager->saveJob(jobSeekerWithoutResume, atsJob);
	Jobs* jobs = savedJobsManager->seeAllSavedJobs(jobSeekerWithResume);
	EXPECT_EQ(jobs->atIndex(0), atsJob);
	EXPECT_EQ(jobs->atIndex(1), JReqJob);
	jobs = savedJobsManager->seeAllSavedJobs(jobSeekerWithoutResume);
	EXPECT_EQ(jobs->atIndex(0), JReqJob);
	EXPECT_EQ(jobs->atIndex(1), atsJob);
}

