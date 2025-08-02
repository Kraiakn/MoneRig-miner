*/

#pragma once

#include <libdevcore/Worker.h>
#include <libethcore/EthashAux.h>
#include <libethcore/Miner.h>

#include <functional>

namespace dev
{
namespace eth
{
class CPUMiner : public Miner
{
public:
    CPUMiner(unsigned _index, CPSettings _settings, DeviceDescriptor& _device);
    ~CPUMiner() override;

    static unsigned getNumDevices();
    static void enumDevices(std::map<string, DeviceDescriptor>& _DevicesCollection);

    void search(const dev::eth::WorkPackage& w);

protected:
    bool initDevice() override;
    bool initEpoch_internal() override;
    void kick_miner() override;

private:
    atomic<bool> m_new_work = {false};
    void workLoop() override;
    CPSettings m_settings;
};


}  // namespace eth
}  // namespace dev
