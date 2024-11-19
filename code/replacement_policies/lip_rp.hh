#ifndef __MEM_CACHE_REPLACEMENT_POLICIES_LIP_RP_HH__
#define __MEM_CACHE_REPLACEMENT_POLICIES_LIP_RP_HH__
#include "mem/cache/replacement_policies/base.hh"
namespace gem5{
    struct LIP9Params:BaseReplacementPolicyParams{};
    namespace replacement_policy{
        class LIP9:public Base{
            protected:
                struct LIP9ReplData:ReplacementData{
                    Tick lastTouchTick;
                    LIP9ReplData():lastTouchTick(0){}
                };
            public:
                typedef LIP9Params Params;
                LIP9(const Params &p);
                ~LIP9()=default;
                void invalidate(const std::shared_ptr<ReplacementData>& replacement_data)override;
                void touch(const std::shared_ptr<ReplacementData>& replacement_data) const override;
                // void reset(const std::shared_ptr<ReplacementData>& replacement_data) const override;
                void reset(const std::shared_ptr<ReplacementData>& replacement_data,std::vector<ReplaceableEntry*> blks) const;
                ReplaceableEntry* getVictim(const ReplacementCandidates& candidates) const override;
                std::shared_ptr<ReplacementData> instantiateEntry() override;
        };
    }
}
#endif
