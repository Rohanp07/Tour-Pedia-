import React from "react";
import { MDBPagination, MDBPaginationItem, MDBBtn } from "mdb-react-ui-kit";

const Pagination = ({
    setCurrentPage,
    currentPage,
    numberOfPages,
    dispatch,
}) => {
    const renderPagination = () => {
        if (currentPage === numberOfPages && currentPage === 1) return null;
        if (currentPage === 1) {
            //if we are on first page
            return (
                <MDBPagination center className="mb-0">
                    <MDBPaginationItem>
                        <p className="fw-bold mt-1">1</p>
                    </MDBPaginationItem>
                    <MDBPaginationItem>
                        <MDBBtn
                            rounded
                            className="mx-2"
                            onClick={() => dispatch(setCurrentPage(currentPage + 1))}
                        >
                            Next
                        </MDBBtn>
                    </MDBPaginationItem>
                </MDBPagination>
            );
        } else if (currentPage !== numberOfPages) {

            //we are on some middle page 
            return (
                <MDBPagination center className="mb-0">
                    <MDBPaginationItem>
                        <MDBBtn
                            rounded
                            className="mx-2"
                            onClick={() => dispatch(setCurrentPage(currentPage - 1))}
                        >
                            Prev
                        </MDBBtn>
                    </MDBPaginationItem>
                    <MDBPaginationItem>
                        <p className="fw-bold mt-1">{currentPage}</p>
                    </MDBPaginationItem>
                    <MDBPaginationItem>
                        <MDBBtn
                            rounded
                            className="mx-2"
                            onClick={() => dispatch(setCurrentPage(currentPage + 1))}
                        >
                            Next
                        </MDBBtn>
                    </MDBPaginationItem>
                </MDBPagination>
            );
        } else {
            return (
                //we are on last page 
                <MDBPagination center className="mb-0">
                    <MDBPaginationItem>
                        <MDBBtn
                            rounded
                            className="mx-2"
                            onClick={() => dispatch(setCurrentPage(currentPage - 1))}
                        >
                            Prev
                        </MDBBtn>
                    </MDBPaginationItem>
                    <MDBPaginationItem>
                        <p className="fw-bold mt-1">{currentPage}</p>
                    </MDBPaginationItem>
                </MDBPagination>
            );
        }
    };

    return <div className="mt-4">{renderPagination()}</div>;
};

export default Pagination;