#include "recruitertest.h"


TEST(RecruiterCanSeeAListOfJobTheyPost, postMutipleJob) {
	Recruiter* recruiter = new Recruiter();
	JobsManager* jobsManager = new JobsManager();
	Job* job = new JReqJob(recruiter);
	jobsManager->postJob(job);
	Jobs* jobs = jobsManager->seeJobsPostBy(recruiter);
	EXPECT_EQ(jobs->atIndex(0), job);
}

TEST(RecruiterCanSeeJobSeekersByJob, seeJobseekerByJob) {
	Recruiter* recruiter = new Recruiter();
	JobsManager* jobsManager = new JobsManager();
	JobApplicationsManager* jobApplicationsManager = new JobApplicationsManager();
	Job* atsJob = new ATSJob(recruiter);
	Job* JReqJob = createJReqJob(recruiter);
	jobsManager->postJob(atsJob);
	jobsManager->postJob(JReqJob);
	JobSeeker* jobSeekerWithResume = createJobSeekerWithResume();
	JobSeeker* jobSeekerWithoutResume = createJobSeekerWithoutResume();
	Date* date;
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, atsJob, date));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, JReqJob, date));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, atsJob, date));
	EXPECT_FALSE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, JReqJob, date));
	JobSeekers* jobSeekers = jobApplicationsManager->jobSeekersWhoApplied(atsJob);
}

TEST(RecruiterCanGetJobSeekersByDate, getJobSeekersByDate) {
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
	JobSeekers* jobSeekers = jobApplicationsManager->jobSeekersAppliedOn(date);
	EXPECT_EQ(jobSeekers->atIndex(0), jobSeekerWithResume);
	EXPECT_EQ(jobSeekers->atIndex(1), jobSeekerWithoutResume);
}
