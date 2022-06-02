import React, { useEffect } from "react";
import { MDBCard, MDBCol, MDBContainer, MDBRow, MDBTypography } from "mdb-react-ui-kit";
import { useDispatch, useSelector } from "react-redux";

import { getTours } from "../redux/features/tourSlice";
import CardTour from "../components/cardTour";

const Home = () => {
  const { tours, loading } = useSelector((state) => ({ ...state.tour }));
  const dispatch = useDispatch();


  useEffect(() => {
    dispatch(getTours());
  }, []);




  if (loading) {
    return <h1>Lodaing ...</h1>
  }

  return (
    <div
      style={{
        margin: "auto",
        padding: "15px",
        maxWidth: "1000px",
        alignContent: "center",
      }}
    >
      <MDBRow className="mt-5">
        {tours.length === 0 && (
          <MDBTypography className="text-center mb-0  " tag="h2">
            No Tours Found
          </MDBTypography>
        )

        }

        <MDBCol>
          <MDBContainer>
            <MDBRow className="row-cols-1 row-cols-md-3  g-2">
              {
                tours && tours.map((tour, idx) => (
                  <CardTour key={idx} {...tour} />
                ))
              }
            </MDBRow>
          </MDBContainer>
        </MDBCol>

      </MDBRow>

    </div>
  )
}

export default Home