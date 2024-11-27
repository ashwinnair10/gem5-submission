#include "mem/cache/replacement_policies/lip_rp.hh"
#include<cassert>
#include<memory>
#include "params/LIPRP.hh"
#include "sim/cur_tick.hh"
namespace gem5{
    namespace replacement_policy{
        LIP9::LIP9(const Params &p):Base(p){}
        void LIP9::invalidate(const std::shared_ptr<ReplacementData>& replacement_data){
            std::static_pointer_cast<LIP9ReplData>(replacement_data)->lastTouchTick=Tick(0);
        }
        void LIP9::touch(const std::shared_ptr<ReplacementData>& replacement_data)const{
            std::static_pointer_cast<LIP9ReplData>(replacement_data)->lastTouchTick=curTick();
        }
        // void LIP9::reset(const std::shared_ptr<ReplacementData>& replacement_data)const{
        //     std::static_pointer_cast<LIP9ReplData>(replacement_data)->lastTouchTick=curTick();
        // }
        void LIP9::reset(const std::shared_ptr<ReplacementData>& replacement_data,std::vector<ReplaceableEntry*> blks)const{
            // std::static_pointer_cast<LIP9ReplData>(replacement_data)->lastTouchTick=curTick();
            std::sort(blks.begin(),blks.end(),[](ReplaceableEntry* a,ReplaceableEntry* b){return std::static_pointer_cast<LIP9ReplData>(a->replacementData)->lastTouchTick<std::static_pointer_cast<LIP9ReplData>(b->replacementData)->lastTouchTick;});
            std::static_pointer_cast<LIP9ReplData>(replacement_data)->lastTouchTick=std::static_pointer_cast<LIP9ReplData>(blks[8]->replacementData)->lastTouchTick;
            // invalidate(blks[9]->replacementData);
            std::static_pointer_cast<LIP9ReplData>(blks[8]->replacementData)->lastTouchTick--;
        }
        ReplaceableEntry* LIP9::getVictim(const ReplacementCandidates& candidates)const{
            assert(candidates.size()>0);
            ReplaceableEntry* victim=candidates[0];
            for (const auto& candidate:candidates){
                if(std::static_pointer_cast<LIP9ReplData>(candidate->replacementData)->lastTouchTick<std::static_pointer_cast<LIP9ReplData>(victim->replacementData)->lastTouchTick){
                    victim=candidate;
                }
            }
            return victim;
        }
        std::shared_ptr<ReplacementData> LIP9::instantiateEntry(){
            return std::shared_ptr<ReplacementData>(new LIP9ReplData());
        }
    }
}
