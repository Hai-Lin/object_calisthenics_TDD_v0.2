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
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, atsJob));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithResume, JReqJob));
	EXPECT_TRUE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, atsJob));
	EXPECT_FALSE(jobApplicationsManager->applyJob(jobSeekerWithoutResume, JReqJob));
	JobSeekers* jobSeekers = jobApplicationsManager->jobSeekersWhoApplied(atsJob);
}
