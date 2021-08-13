#include <torch/csrc/distributed/autograd/rpc_messages/rref_backward_resp.h>

namespace torch {
namespace distributed {
namespace autograd {

c10::intrusive_ptr<rpc::OutgoingMessage> RRefBackwardResp::toMessageImpl(const std::string& meta) && {
  return c10::make_intrusive<rpc::OutgoingMessage>(
      std::vector<char>{},
      std::vector<torch::Tensor>{},
      rpc::MessageType::RREF_BACKWARD_RESP,
      meta);
}

std::unique_ptr<RRefBackwardResp> RRefBackwardResp::fromMessage(
    const rpc::Message& message) {
  TORCH_INTERNAL_ASSERT(message.type() == rpc::MessageType::RREF_BACKWARD_RESP);
  return std::unique_ptr<RRefBackwardResp>();
}

} // namespace autograd
} // namespace distributed
} // namespace torch
