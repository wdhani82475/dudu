#初次完成
#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
struct AdIdea {
	int64_t idea_id = 0;  // 全局唯一自增id
	int idea_type = 0;
	std::string account_id;
	std::string adplan_id;
	std::string scheduling_id;
	int cast_way = 0;  // 0:cpm 1:cpc
	int64_t float_bid = 0; // TODO:wtf?
	int64_t idea_create_time = 0;
	int64_t idea_update_time = 0;
};

struct AdAccount {
	std::string account_id;
	std::string industry_level1_id;
	std::string industry_level2_id;
};

struct RawAdIdea {
	int64_t id;
	double w;
	std::shared_ptr<AdIdea>_ad_idea;
	std::shared_ptr<AdAccount>_ad_account;

	RawAdIdea():id(0), w(0.0f), _ad_idea(nullptr), _ad_account(nullptr)
	{
	}
	RawAdIdea(int64_t _d, std::shared_ptr<AdIdea> ad_idea, std::shared_ptr<AdAccount> ad_account):id(_d),w(0.0f),
	_ad_idea(ad_idea), _ad_account(ad_account) 
	{
	}
	RawAdIdea(int64_t _d, std::shared_ptr<AdIdea> ad_idea,std::shared_ptr<AdAccount>ad_account,double _w):id(_d),w(_w),_ad_idea(ad_idea),_ad_account(ad_account)
	{
	}
	RawAdIdea(const RawAdIdea& raw):id(raw.id),w(raw.w),_ad_idea(raw._ad_idea),_ad_account(raw._ad_account) 
	{
	}
};
int main()
{
	std::vector<RawAdIdea> newad_idea;
	std::sort(newad_idea.begin(),newad_idea.end(),[] (std::shared_ptr<AdIdea>& l,std::shared_ptr<AdIdea>& r)
			{
				return l->float_bid>r->float_bid;
			});
	return 0;
}
